#ifndef DUNGEONKEYRINGMESSAGE_H
#define DUNGEONKEYRINGMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class DungeonKeyRingMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_DungeonKeyRingMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_DungeonKeyRingMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_DungeonKeyRingMessage(FuncTree tree);
  DungeonKeyRingMessage();

  QList<uint> availables;
  QList<uint> unavailables;

private:
  void _availablestreeFunc(Reader *input);
  void _availablesFunc(Reader *input);
  void _unavailablestreeFunc(Reader *input);
  void _unavailablesFunc(Reader *input);

  FuncTree _availablestree;
  FuncTree _unavailablestree;
};

#endif // DUNGEONKEYRINGMESSAGE_H