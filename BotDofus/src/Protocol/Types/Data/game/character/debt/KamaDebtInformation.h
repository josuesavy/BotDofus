#ifndef KAMADEBTINFORMATION_H
#define KAMADEBTINFORMATION_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/character/debt/DebtInformation.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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