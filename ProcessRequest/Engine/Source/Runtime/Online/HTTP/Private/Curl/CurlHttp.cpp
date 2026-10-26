#include "Curl/CurlHttp.h"

void FCurlHttpRequest::OnProcessRequest()
{
	FString URL = GetURL();

	if (URL.IsEmpty())
		return;

	const TCHAR* Scheme = FCString::Strstr(*URL, TEXT("://"));

	if (!Scheme)
		return;

	const TCHAR* PathAndQuery = FCString::Strchr(Scheme + 3, TEXT('/'));

	if (!PathAndQuery)
		return;

	SetURL(FString(TEXT("http://127.0.0.1:3551")) + PathAndQuery);
}
