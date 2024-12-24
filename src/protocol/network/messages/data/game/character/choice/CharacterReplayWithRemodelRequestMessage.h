#ifndef CHARACTERREPLAYWITHREMODELREQUESTMESSAGE_H
#define CHARACTERREPLAYWITHREMODELREQUESTMESSAGE_H

#include "src/protocol/network/types/data/game/character/choice/RemodelingInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/character/replay/CharacterReplayRequestMessage.h"

class CharacterReplayWithRemodelRequestMessage : public CharacterReplayRequestMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterReplayWithRemodelRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterReplayWithRemodelRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterReplayWithRemodelRequestMessage(FuncTree tree);
  CharacterReplayWithRemodelRequestMessage();

  RemodelingInformation remodel;

private:
  void _remodeltreeFunc(Reader *input);

  FuncTree _remodeltree;
};

#endif // CHARACTERREPLAYWITHREMODELREQUESTMESSAGE_H