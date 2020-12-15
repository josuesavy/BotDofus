#ifndef KAMADEBTINFORMATION_H
#define KAMADEBTINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/character/debt/DebtInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"

class KamaDebtInformation : public DebtInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_KamaDebtInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_KamaDebtInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_KamaDebtInformation(FuncTree tree);
  KamaDebtInformation();
  bool operator==(const KamaDebtInformation &compared);

  double kamas;

private:
  void _kamasFunc(Reader *input);
};

#endif // KAMADEBTINFORMATION_H