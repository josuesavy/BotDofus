#ifndef TAXCOLLECTORGUILDINFORMATIONS_H
#define TAXCOLLECTORGUILDINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/BasicGuildInformations.h"
#include "src/protocol/types/data/game/guild/tax/TaxCollectorComplementaryInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

class TaxCollectorGuildInformations : public TaxCollectorComplementaryInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorGuildInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorGuildInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorGuildInformations(FuncTree tree);
  TaxCollectorGuildInformations();
  bool operator==(const TaxCollectorGuildInformations &compared);

  QSharedPointer<BasicGuildInformations> guild;

private:
  void _guildtreeFunc(Reader *input);

  FuncTree _guildtree;
};

#endif // TAXCOLLECTORGUILDINFORMATIONS_H