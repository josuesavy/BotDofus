#ifndef TREASUREHUNTSHOWLEGENDARYUIMESSAGE_H
#define TREASUREHUNTSHOWLEGENDARYUIMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class TreasureHuntShowLegendaryUIMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TreasureHuntShowLegendaryUIMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TreasureHuntShowLegendaryUIMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TreasureHuntShowLegendaryUIMessage(FuncTree tree);
  TreasureHuntShowLegendaryUIMessage();

  QList<uint> availableLegendaryIds;

private:
  void _availableLegendaryIdstreeFunc(Reader *input);
  void _availableLegendaryIdsFunc(Reader *input);

  FuncTree _availableLegendaryIdstree;
};

#endif // TREASUREHUNTSHOWLEGENDARYUIMESSAGE_H