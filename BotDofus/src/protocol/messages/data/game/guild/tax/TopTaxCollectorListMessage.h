#ifndef TOPTAXCOLLECTORLISTMESSAGE_H
#define TOPTAXCOLLECTORLISTMESSAGE_H

#include "src/protocol/types/data/game/guild/tax/TaxCollectorInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/guild/tax/AbstractTaxCollectorListMessage.h"

class TopTaxCollectorListMessage : public AbstractTaxCollectorListMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TopTaxCollectorListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TopTaxCollectorListMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TopTaxCollectorListMessage(FuncTree tree);
  TopTaxCollectorListMessage();

  bool isDungeon;

private:
  void _isDungeonFunc(Reader *input);
};

#endif // TOPTAXCOLLECTORLISTMESSAGE_H