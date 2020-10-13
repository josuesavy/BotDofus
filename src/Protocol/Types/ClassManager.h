#ifndef CLASSMANAGER_H
#define CLASSMANAGER_H

#include "src/Engines/IO/Singleton.h"
#include "src/Protocol/Types/AbstractClass.h"

class ClassManagerSingleton;

class ClassManager
{
  friend Singleton<ClassManager>;

public:
  QSharedPointer<AbstractClass> getClass(int classId);
};

class ClassManagerSingleton : public Singleton<ClassManager>
{};

#endif // CLASSMANAGER_H