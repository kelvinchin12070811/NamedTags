CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
SET(CMAKE_CXX_STANDARD 17)
SET(SRCS
	ArrayTag.hpp
	CommonTags.hpp
	CompoundTag.cpp
	json.hpp
	JsonSerializer.hpp
	JsonSerializer.cpp
	ObserverTag.hpp
	ObserverTag.cpp
	Serializer.hpp
	TagBase.hpp
	WrapperTag.hpp
)

ADD_LIBRARY(NamedTags STATIC ${SRCS})
TARGET_INCLUDE_DIRECTORIES(NamedTags PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")