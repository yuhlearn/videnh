#ifndef FILESYSTEM_UTILS_H
#define FILESYSTEM_UTILS_H

#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

typedef std::string path_t;
#define PATHSTR(X) X

static bool path_is_directory(const path_t &path)
{
    struct stat s;
    if (stat(path.c_str(), &s) != 0)
        return false;
    return S_ISDIR(s.st_mode);
}

static int list_directory(const path_t &dirpath, std::vector<path_t> &imagepaths)
{
    imagepaths.clear();

    DIR *dir = opendir(dirpath.c_str());
    if (!dir)
    {
        fprintf(stderr, "opendir failed %s\n", dirpath.c_str());
        return -1;
    }

    struct dirent *ent = 0;
    while ((ent = readdir(dir)))
    {
        if (ent->d_type != DT_REG)
            continue;

        imagepaths.push_back(path_t(ent->d_name));
    }

    closedir(dir);
    std::sort(imagepaths.begin(), imagepaths.end());

    return 0;
}

static path_t get_file_name_without_extension(const path_t &path)
{
    size_t dot = path.rfind(PATHSTR('.'));
    if (dot == path_t::npos)
        return path;

    return path.substr(0, dot);
}

static path_t get_file_extension(const path_t &path)
{
    size_t dot = path.rfind(PATHSTR('.'));
    if (dot == path_t::npos)
        return path_t();

    return path.substr(dot + 1);
}

static path_t get_executable_directory()
{
    char filepath[256];
    readlink("/proc/self/exe", filepath, 256);

    char *slash = strrchr(filepath, '/');
    slash[1] = '\0';

    return path_t(filepath);
}

static bool filepath_is_readable(const path_t &path)
{
    FILE *fp = fopen(path.c_str(), "rb");
    if (!fp)
        return false;

    fclose(fp);
    return true;
}

static path_t sanitize_filepath(const path_t &path)
{
    if (filepath_is_readable(path))
        return path;

    return get_executable_directory() + path;
}

#endif // FILESYSTEM_UTILS_H
