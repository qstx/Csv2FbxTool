#pragma once

#if defined(DEBUG) || defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

#include <assert.h>
#include <memory>
#include <iostream>
#include <vector>

#include "framework.h"
#include <Windows.h>

#include "Core/Base.h"
#include "Core/Application.h"
#include "Core/Window.h"