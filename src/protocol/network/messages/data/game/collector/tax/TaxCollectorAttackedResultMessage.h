#ifndef TAXCOLLECTORATTACKEDRESULTMESSAGE_H
#define TAXCOLLECTORATTACKEDRESULTMESSAGE_H

#include "src/protocol/types/data/game/collector/tax/TaxCollectorBasicInformations.h"
#include "src/protocol/types/data/game/context/roleplay/BasicAllianceInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class TaxCollectorAttackedResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorAttackedResultMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorAttackedResultMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorAttackedResultMessage(FuncTree tree);
  TaxCollectorAttackedResultMessage();

  bool deadOrAlive;
  TaxCollectorBasicInformations basicInfos;
  QSharedPointer<BasicAllianceInformations> alliance;

private:
  void _deadOrAliveFunc(Reader *input);
  void _basicInfostreeFunc(Reader *input);
  void _alliancetreeFunc(Reader *input);

  FuncTree _basicInfostree;
  FuncTree _alliancetree;
};

#endif // TAXCOLLECTORATTACKEDRESULTMESSAGE_H