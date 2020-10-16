#ifndef PADDOCKINSTANCESINFORMATIONS_H
#define PADDOCKINSTANCESINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/paddock/PaddockBuyableInformations.h"
#include "src/Protocol/Types/Data/game/paddock/PaddockInformations.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class PaddockInstancesInformations : public PaddockInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PaddockInstancesInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PaddockInstancesInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PaddockInstancesInformations(FuncTree tree);
  PaddockInstancesInformations();
  bool operator==(const PaddockInstancesInformations &compared);

  QList<QSharedPointer<PaddockBuyableInformations>> paddocks;

private:
  void _paddockstreeFunc(Reader *input);
  void _paddocksFunc(Reader *input);

  FuncTree _paddockstree;
};

#endif // PADDOCKINSTANCESINFORMATIONS_H