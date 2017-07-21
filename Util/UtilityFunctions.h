#ifndef UTILITY_FUNCTIONS_H
#define UTILITY_FUNCTIONS_H

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
// #include <jsoncpp/json/json.h>
#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/insert_linebreaks.hpp>
#include <boost/archive/iterators/transform_width.hpp>
#include <boost/archive/iterators/ostream_iterator.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/remove_whitespace.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "LogBase.h"
#include "sgx_urts.h"
#include "Base64.h"

using namespace std;
using namespace boost::archive::iterators;
using boost::lexical_cast;
using boost::uuids::uuid;
using boost::uuids::random_generator;

#define FILE_UUID_LENGTH 32

typedef struct _sgx_errlist_t {
    sgx_status_t err;
    const char *msg;
    const char *sug; /* Suggestion */
} sgx_errlist_t;

void print_error_message(sgx_status_t ret);

void SafeFree(void *ptr);

string GetRandomString();

string ByteArrayToString(const uint8_t *arr, int size);
string ByteArrayToStringNoFill(const uint8_t *arr, int size);
int StringToByteArray(string str, uint8_t **arr);
string ByteArrayToNoHexString(const uint8_t *arr, int size);
string UIntToString(uint32_t *arr, int size);
int HexStringToByteArray(string str, uint8_t **arr);

int ReadFileToBuffer(string filePath, uint8_t **content);
int ReadFileToBuffer(string filePath, char **content);
int SaveBufferToFile(string filePath, string content);
int RemoveFile(string filePath);

string Base64encode(const string val);
string Base64decode(const string val);
string Base64encodeUint8(uint8_t *val, uint32_t len);

#endif


