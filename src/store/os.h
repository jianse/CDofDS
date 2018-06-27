/*

 * os.h
 *
 *  Created on: 2018年6月16日
 *      Author: lee

*
 * 这个头文件提供了对系统相关操作的支持，
 * 以便让程序能够在各种平台上正常运行。


#ifndef STORE_OS_H_
#define STORE_OS_H_


** Wrapper around OS specific sqlite3_os_init() function.

int sqlite3OsInit(void);


** Functions for accessing sqlite3_file methods

void sqlite3OsClose(sqlite3_file*);
int sqlite3OsRead(sqlite3_file*, void*, int amt, i64 offset);
int sqlite3OsWrite(sqlite3_file*, const void*, int amt, i64 offset);
int sqlite3OsTruncate(sqlite3_file*, i64 size);
int sqlite3OsSync(sqlite3_file*, int);
int sqlite3OsFileSize(sqlite3_file*, i64 *pSize);
int sqlite3OsLock(sqlite3_file*, int);
int sqlite3OsUnlock(sqlite3_file*, int);
int sqlite3OsCheckReservedLock(sqlite3_file *id, int *pResOut);
int sqlite3OsFileControl(sqlite3_file*,int,void*);
void sqlite3OsFileControlHint(sqlite3_file*,int,void*);

int sqlite3OsSectorSize(sqlite3_file *id);
int sqlite3OsDeviceCharacteristics(sqlite3_file *id);
#ifndef SQLITE_OMIT_WAL
int sqlite3OsShmMap(sqlite3_file *,int,int,int,void volatile **);
int sqlite3OsShmLock(sqlite3_file *id, int, int, int);
void sqlite3OsShmBarrier(sqlite3_file *id);
int sqlite3OsShmUnmap(sqlite3_file *id, int);
#endif  SQLITE_OMIT_WAL
int sqlite3OsFetch(sqlite3_file *id, i64, int, void **);
int sqlite3OsUnfetch(sqlite3_file *, i64, void *);



** Functions for accessing sqlite3_vfs methods

int sqlite3OsOpen(sqlite3_vfs *, const char *, sqlite3_file*, int, int *);
int sqlite3OsDelete(sqlite3_vfs *, const char *, int);
int sqlite3OsAccess(sqlite3_vfs *, const char *, int, int *pResOut);
int sqlite3OsFullPathname(sqlite3_vfs *, const char *, int, char *);
#ifndef SQLITE_OMIT_LOAD_EXTENSION
void *sqlite3OsDlOpen(sqlite3_vfs *, const char *);
void sqlite3OsDlError(sqlite3_vfs *, int, char *);
void (*sqlite3OsDlSym(sqlite3_vfs *, void *, const char *))(void);
void sqlite3OsDlClose(sqlite3_vfs *, void *);
#endif  SQLITE_OMIT_LOAD_EXTENSION
int sqlite3OsRandomness(sqlite3_vfs *, int, char *);
int sqlite3OsSleep(sqlite3_vfs *, int);
int sqlite3OsGetLastError(sqlite3_vfs*);
int sqlite3OsCurrentTimeInt64(sqlite3_vfs *, sqlite3_int64*);


** Convenience functions for opening and closing files using
** sqlite3_malloc() to obtain space for the file-handle structure.

int sqlite3OsOpenMalloc(sqlite3_vfs *, const char *, sqlite3_file **, int,int*);
void sqlite3OsCloseFree(sqlite3_file *);



#endif  STORE_OS_H_
*/
