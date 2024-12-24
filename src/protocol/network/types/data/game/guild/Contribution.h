#ifndef CONTRIBUTION_H
#define CONTRIBUTION_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class Contribution : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_Contribution(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_Contribution(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_Contribution(FuncTree tree);
  Contribution();
  bool operator==(const Contribution &compared);

  double contributorId;
  QString contributorName;
  double amount;

private:
  void _contributorIdFunc(Reader *input);
  void _contributorNameFunc(Reader *input);
  void _amountFunc(Reader *input);
};

#endif // CONTRIBUTION_H