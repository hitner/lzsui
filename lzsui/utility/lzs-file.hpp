#pragma once
#include <stdio.h>
#include <cassert>


int read_file(const wchar_t * filename, void * buf, size_t bufsize)
{
	assert(filename);
	assert(buf);
	assert(bufsize > 0);
	if (filename == NULL || buf == NULL || bufsize <= 0) {
		return 0;
	}
	FILE * stream = NULL;
	errno_t error = _wfopen_s(&stream, filename, L"rb");
	assert(error == 0);
	size_t readnum = 0;
	if (error == 0) {
		readnum = fread_s(buf, bufsize, 1, bufsize, stream);
		//need check later
	}
	if (stream) {
		int ret = fclose(stream);
		assert(ret == 0);
	}
	return readnum;
}