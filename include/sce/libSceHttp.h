#pragma once

#include <stdint.h>

#define SCE_HTTP_TRUE				(int)(1)
#define SCE_HTTP_FALSE				(int)(0)

#define SCE_HTTP_ENABLE				SCE_HTTP_TRUE
#define SCE_HTTP_DISABLE			SCE_HTTP_FALSE

#define SCE_HTTP_USERNAME_MAX_SIZE	256
#define SCE_HTTP_PASSWORD_MAX_SIZE	256

typedef enum{
	SCE_HTTP_VERSION_1_0=1,
	SCE_HTTP_VERSION_1_1
} SceHttpHttpVersion;

typedef enum{
	SCE_HTTP_PROXY_AUTO,
	SCE_HTTP_PROXY_MANUAL
} SceHttpProxyMode;

typedef enum{
	SCE_HTTP_HEADER_OVERWRITE,
	SCE_HTTP_HEADER_ADD
} SceHttpAddHeaderMode;

typedef enum{
	SCE_HTTP_AUTH_BASIC,
	SCE_HTTP_AUTH_DIGEST,
	SCE_HTTP_AUTH_RESERVED0,
	SCE_HTTP_AUTH_RESERVED1,
	SCE_HTTP_AUTH_RESERVED2
} SceHttpAuthType;

typedef enum {
	SCE_HTTP_CONTENTLEN_EXIST,
	SCE_HTTP_CONTENTLEN_NOT_FOUND,
	SCE_HTTP_CONTENTLEN_CHUNK_ENC
} SceHttpContentLengthType;

typedef enum {
	SCE_HTTP_REQUEST_STATUS_CONNECTION_RESERVED,
	SCE_HTTP_REQUEST_STATUS_RESOLVING_NAME,
	SCE_HTTP_REQUEST_STATUS_NAME_RESOLVED,
	SCE_HTTP_REQUEST_STATUS_CONNECTING,
	SCE_HTTP_REQUEST_STATUS_CONNECTED,
	SCE_HTTP_REQUEST_STATUS_TLS_CONNECTING,
	SCE_HTTP_REQUEST_STATUS_TLS_CONNECTED,
	SCE_HTTP_REQUEST_STATUS_SENDING_REQUEST,
	SCE_HTTP_REQUEST_STATUS_REQUEST_SENT,
	SCE_HTTP_REQUEST_STATUS_RECEIVING_HEADER,
	SCE_HTTP_REQUEST_STATUS_HEADER_RECEIVED,
} SceHttpRequestStatus;

#define SCE_HTTP_DEFAULT_RESOLVER_TIMEOUT		(0)	// libnet default
#define SCE_HTTP_DEFAULT_RESOLVER_RETRY			(0)	// libnet default
#define SCE_HTTP_DEFAULT_CONNECT_TIMEOUT		(30* 1000 * 1000U)
#define SCE_HTTP_DEFAULT_SEND_TIMEOUT			(120* 1000 * 1000U)
#define SCE_HTTP_DEFAULT_RECV_TIMEOUT			(120* 1000 * 1000U)
#define SCE_HTTP_DEFAULT_RECV_BLOCK_SIZE		(1500U)
#define SCE_HTTP_DEFAULT_RESPONSE_HEADER_MAX	(5000U)
#define SCE_HTTP_DEFAULT_REDIRECT_MAX			(6U)
#define SCE_HTTP_DEFAULT_TRY_AUTH_MAX			(6U)

#define SCE_HTTP_INVALID_ID						0

#if defined(_LANGUAGE_C_PLUS_PLUS)||defined(__cplusplus)||defined(c_plusplus)
extern "C" {
#endif	/* defined(_LANGUAGE_C_PLUS_PLUS)||defined(__cplusplus)||defined(c_plusplus) */

typedef int (*SceHttpAuthInfoCallback)(
	int request,
	SceHttpAuthType authType,
	const char *realm,
	char *username,
	char *password,
	int  isNeedEntity,
	uint8_t **entityBody,
	size_t *entitySize,
	int *isSave,
	void *userArg);

typedef int (*SceHttpRedirectCallback)(
	int request,
	int32_t statusCode,
	int32_t *method,
	const char *location,
	void *userArg);

typedef void (*SceHttpRequestStatusCallback)(
	int request,
	SceHttpRequestStatus requestStatus,
	void *userArg);

typedef struct SceHttpMemoryPoolStats{
	size_t		poolSize;
	size_t		maxInuseSize;
	size_t		currentInuseSize;
	int32_t	reserved;
} SceHttpMemoryPoolStats;

int sceHttpInit(int libnetMemId, int libsslCtxId, size_t poolSize);
int sceHttpTerm(int libhttpCtxId);
int sceHttpGetMemoryPoolStats(int libhttpCtxId, SceHttpMemoryPoolStats* currentStat);

int sceHttpCreateTemplate(int libhttpCtxId, const char *userAgent, int httpVer, int isAutoProxyConf);
int sceHttpDeleteTemplate(int tmplId);
int sceHttpCreateConnection(int tmplId, const char *serverName, const char *scheme, uint16_t port, int isEnableKeepalive);
int sceHttpCreateConnectionWithURL(int tmplId, const char *url, int isEnableKeepalive);
int sceHttpDeleteConnection(int connId);
int sceHttpCreateRequest(int connId, int method, const char *path, uint64_t	contentLength);
int sceHttpCreateRequest2(int connId, const char* method, const char *path, uint64_t contentLength);
int sceHttpCreateRequestWithURL(int connId, int method, const char *url, uint64_t contentLength);
int sceHttpCreateRequestWithURL2(int connId, const char* method, const char *url, uint64_t contentLength);
int sceHttpDeleteRequest(int reqId);
int sceHttpSetRequestContentLength(int id, uint64_t contentLength);
int sceHttpSetChunkedTransferEnabled(int id, int isEnable);
int sceHttpSetInflateGZIPEnabled(int id, int isEnable);

int sceHttpSendRequest(int reqId, const void *postData, size_t size);
int sceHttpAbortRequest(int reqId);
int sceHttpGetResponseContentLength(int reqId, int* result, uint64_t *contentLength);
int sceHttpGetStatusCode(int reqId, int *statusCode);
int sceHttpGetAllResponseHeaders(int reqId, char **header, size_t *headerSize);
int sceHttpReadData(int reqId, void *data, size_t size);
int sceHttpAddRequestHeader(int id, const char *name, const char *value, uint32_t mode);
int sceHttpRemoveRequestHeader(int id, const char *name);

int sceHttpParseResponseHeader(const char *header, size_t headerLen, const char *fieldStr, const char **fieldValue, size_t *valueLen);
int sceHttpParseStatusLine(const char *statusLine, size_t lineLen, int *httpMajorVer, int *httpMinorVer, int *responseCode, const char **reasonPhrase, size_t *phraseLen);
int sceHttpSetResponseHeaderMaxSize(int id, size_t headerSize);

int sceHttpSetAuthInfoCallback(int id, SceHttpAuthInfoCallback cbfunc, void *userArg);
int sceHttpSetAuthEnabled(int id, int isEnable);
int sceHttpGetAuthEnabled(int id, int *isEnable);
int sceHttpAuthCacheFlush(int libhttpCtxId);
int sceHttpSetRedirectCallback(int id, SceHttpRedirectCallback cbfunc, void *userArg);
int sceHttpSetAutoRedirect(int id, int isEnable);
int sceHttpGetAutoRedirect(int id, int *isEnable);
int sceHttpRedirectCacheFlush(int libhttpCtxId);
int sceHttpSetResolveTimeOut(int id, uint32_t usec);
int sceHttpSetResolveRetry(int id, int retry);
int sceHttpSetConnectTimeOut(int id, uint32_t usec);
int sceHttpSetSendTimeOut(int id, uint32_t usec);
int sceHttpSetRecvTimeOut(int id, uint32_t usec);
int sceHttpSetRequestStatusCallback(int id, SceHttpRequestStatusCallback cbfunc, void* userArg);

int sceHttpGetLastErrno(int reqId, int* errNum);

typedef void* SceHttpEpollHandle;

#define	SCE_HTTP_NB_EVENT_IN			0x00000001
#define	SCE_HTTP_NB_EVENT_OUT			0x00000002
#define	SCE_HTTP_NB_EVENT_SOCK_ERR		0x00000008
#define	SCE_HTTP_NB_EVENT_HUP			0x00000010
#define SCE_HTTP_NB_EVENT_ICM			0x00000020
#define	SCE_HTTP_NB_EVENT_RESOLVED		0x00010000
#define	SCE_HTTP_NB_EVENT_RESOLVER_ERR	0x00020000

typedef struct SceHttpNBEvent {
	uint32_t	events;
	uint32_t	eventDetail;
	int			id;
	void*		userArg;
} SceHttpNBEvent;

int sceHttpSetNonblock(int id, int isEnable);
int sceHttpGetNonblock(int id, int *isEnable);
int sceHttpTrySetNonblock(int id, int isEnable);
int sceHttpTryGetNonblock(int id, int *isEnable);
int sceHttpCreateEpoll(int libhttpCtxId, SceHttpEpollHandle* eh);
int sceHttpSetEpoll(int id, SceHttpEpollHandle eh, void *userArg);
int sceHttpUnsetEpoll(int id);
int sceHttpGetEpoll(int id, SceHttpEpollHandle* eh, void **userArg);
int sceHttpDestroyEpoll(int libhttpCtxId, SceHttpEpollHandle eh);
int sceHttpWaitRequest(SceHttpEpollHandle eh, SceHttpNBEvent* nbev, int maxevents, int timeout);
int sceHttpAbortWaitRequest(SceHttpEpollHandle eh);
