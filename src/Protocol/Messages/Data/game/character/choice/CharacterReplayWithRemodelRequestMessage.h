#ifndef CHARACTERREPLAYWITHREMODELREQUESTMESSAGE_H
#define CHARACTERREPLAYWITHREMODELREQUESTMESSAGE_H

#include "src/Protocol/Types/Data/game/character/choice/RemodelingInformation.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/character/replay/CharacterReplayRequestMessage.h"

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