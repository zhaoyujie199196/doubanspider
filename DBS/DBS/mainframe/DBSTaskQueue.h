#pragma once

#include "core/DBSQueue.h"
#include <memory>
#include "IDBSTask.h"

typedef DBSQueue<std::shared_ptr<IDBSTask>> DBSTaskQueue;