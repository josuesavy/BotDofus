#ifndef ACCOUNTTAGINFORMATION_H
#define ACCOUNTTAGINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class AccountTagInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AccountTagInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AccountTagInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AccountTagInformation(FuncTree tree);
  AccountTagInformation();
  bool operator==(const AccountTagInformation &compared);

  QString nickname;
  QString tagNumber;

private:
  void _nicknameFunc(Reader *input);
  void _tagNumberFunc(Reader *input);
};

#endif // ACCOUNTTAGINFORMATION_H