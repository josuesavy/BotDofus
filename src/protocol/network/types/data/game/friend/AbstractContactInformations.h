#ifndef ABSTRACTCONTACTINFORMATIONS_H
#define ABSTRACTCONTACTINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/common/AccountTagInformation.h"
#include "src/utils/io/type/FuncTree.h"

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
  AccountTagInformation accountTag;

private:
  void _accountIdFunc(Reader *input);
  void _accountTagtreeFunc(Reader *input);

  FuncTree _accountTagtree;
};

#endif // ABSTRACTCONTACTINFORMATIONS_H