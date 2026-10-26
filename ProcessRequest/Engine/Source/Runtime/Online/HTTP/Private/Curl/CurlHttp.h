#pragma once

#include "Containers/UnrealString.h"

class FCurlHttpRequest;

namespace
{
	static inline bool (*FCurlHttpRequest__ProcessRequest)(FCurlHttpRequest* CurlHttpRequest) = nullptr;
}

class FCurlHttpRequest /*: public IHttpThreadedRequest*/
{
public:
	static bool ProcessRequest(FCurlHttpRequest* CurlHttpRequest);

public:
	FString GetURL() const /*override*/;
	void SetURL(const FString& InURL) /*override*/;

public:
	void OnProcessRequest();
};
