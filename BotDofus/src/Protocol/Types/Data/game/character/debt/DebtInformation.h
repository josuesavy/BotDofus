#ifndef DEBTINFORMATION_H
#define DEBTINFORMATION_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class DebtInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_DebtInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_DebtInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_DebtInformation(FuncTree tree);
  DebtInformation();
  bool operator==(const DebtInformation &compared);

  double id;
  double timestamp;

private:
  void _idFunc(Reader *input);
  void _timestampFunc(Reader *input);
};

#endif // DEBTINFORMATION_H