# ProcessRequest

this was created for fortnite version 30.00, but by modifying the signatures and offsets, it can (presumably) be used for any game built on Unreal Engine


# Sig

FMemory::Malloc -> "48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 83 EC ? 4C 8B 25 ? ? ? ? 33 ED"

FMemory::Realloc -> "40 53 56 41 56 41 57 48 83 EC ? 4C 8B 35"

FMemory::Free -> "48 85 C9 0F 84 ? ? ? ? 57 48 83 EC ? 4C 89 74 24"

FEngineVersion::Current -> "40 53 48 83 EC ? 65 48 8B 04 25 ? ? ? ? B9 ? ? ? ? 48 8B 00 8B 04 01 39 05 ? ? ? ? 7F ? 48 8B 05 ? ? ? ? 48 83 C4 ? 5B C3 48 8D 0D ? ? ? ? E8 ? ? ? ? 83 3D ? ? ? ? ? 75 ? 48 8D 1D ? ? ? ? 48 8B CB E8 ? ? ? ? 48 8D 0D ? ? ? ? 48 89 1D ? ? ? ? E8 ? ? ? ? 48 8D 0D ? ? ? ? E8 ? ? ? ? EB ? E9"

FCurlHttpRequest::ProcessRequest -> "40 55 53 56 57 41 56 41 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 45 33 FF 48 8D 05"


# Off

FCurlHttpRequest::URL -> 0x278
