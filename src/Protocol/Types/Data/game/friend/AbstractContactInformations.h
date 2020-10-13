#ifndef ABSTRACTCONTACTINFORMATIONS_H
#define ABSTRACTCONTACTINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class AbstractContactInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AbstractContactInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AbstractContactInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AbstractContactInformations(FuncTree tree);
  AbstractContactInformations();
  bool operator==(const AbstractContactInformations &compared);

  uint accountId;
  QString accountName;

private:
  void _accountIdFunc(Reader *input);
  void _accountNameFunc(Reader *input);
};

#endif // ABSTRACTCONTACTINFORMATIONS_H