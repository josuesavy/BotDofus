#ifndef ENTITYINFORMATION_H
#define ENTITYINFORMATION_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class EntityInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_EntityInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_EntityInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_EntityInformation(FuncTree tree);
  EntityInformation();
  bool operator==(const EntityInformation &compared);

  uint id;
  uint experience;
  bool status;

private:
  void _idFunc(Reader *input);
  void _experienceFunc(Reader *input);
  void _statusFunc(Reader *input);
};

#endif // ENTITYINFORMATION_H