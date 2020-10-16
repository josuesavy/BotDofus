#ifndef TAXCOLLECTORATTACKEDRESULTMESSAGE_H
#define TAXCOLLECTORATTACKEDRESULTMESSAGE_H

#include "src/Protocol/Types/Data/game/guild/tax/TaxCollectorBasicInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/BasicGuildInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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
  QSharedPointer<BasicGuildInformations> guild;

private:
  void _deadOrAliveFunc(Reader *input);
  void _basicInfostreeFunc(Reader *input);
  void _guildtreeFunc(Reader *input);

  FuncTree _basicInfostree;
  FuncTree _guildtree;
};

#endif // TAXCOLLECTORATTACKEDRESULTMESSAGE_H