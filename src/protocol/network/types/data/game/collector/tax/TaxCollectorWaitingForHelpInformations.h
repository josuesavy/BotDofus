#ifndef TAXCOLLECTORWAITINGFORHELPINFORMATIONS_H
#define TAXCOLLECTORWAITINGFORHELPINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/fight/ProtectedEntityWaitingForHelpInfo.h"
#include "src/protocol/types/data/game/collector/tax/TaxCollectorComplementaryInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

class TaxCollectorWaitingForHelpInformations : public TaxCollectorComplementaryInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorWaitingForHelpInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorWaitingForHelpInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorWaitingForHelpInformations(FuncTree tree);
  TaxCollectorWaitingForHelpInformations();
  bool operator==(const TaxCollectorWaitingForHelpInformations &compared);

  ProtectedEntityWaitingForHelpInfo waitingForHelpInfo;

private:
  void _waitingForHelpInfotreeFunc(Reader *input);

  FuncTree _waitingForHelpInfotree;
};

#endif // TAXCOLLECTORWAITINGFORHELPINFORMATIONS_H