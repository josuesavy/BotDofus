#ifndef TREASUREHUNTLEGENDARYREQUESTMESSAGE_H
#define TREASUREHUNTLEGENDARYREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class TreasureHuntLegendaryRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TreasureHuntLegendaryRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TreasureHuntLegendaryRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TreasureHuntLegendaryRequestMessage(FuncTree tree);
  TreasureHuntLegendaryRequestMessage();

  uint legendaryId;

private:
  void _legendaryIdFunc(Reader *input);
};

#endif // TREASUREHUNTLEGENDARYREQUESTMESSAGE_H