#include "Curl/CurlHttp.h"

bool FCurlHttpRequest::ProcessRequest(FCurlHttpRequest* CurlHttpRequest)
{
	if (CurlHttpRequest)
		CurlHttpRequest->OnProcessRequest();

	return FCurlHttpRequest__ProcessRequest(CurlHttpRequest);
}
