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
	FString GetURL() const;

	void SetURL(const FString& InURL);

public:
	void OnProcessRequest();

public:
	static bool ProcessRequestHook(FCurlHttpRequest* CurlHttpRequest);
};
