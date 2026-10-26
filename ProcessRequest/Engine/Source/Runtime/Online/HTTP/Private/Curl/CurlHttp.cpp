#include "Curl/CurlHttp.h"

void FCurlHttpRequest::OnProcessRequest()
{
	FString URL = GetURL();

	if (URL.IsEmpty())
		return;

	const TCHAR* Scheme = FCString::Strstr(*URL, TEXT("://"));

	if (!Scheme)
		return;

	const TCHAR* Host = Scheme + 3;
	const TCHAR* Path = FCString::Strchr(Host, TEXT('/'));

	URL = TEXT("http://127.0.0.1:3551");

	if (Path)
		URL += Path;

	SetURL(URL);
}
