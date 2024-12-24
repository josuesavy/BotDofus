#ifndef CHARACTERSELECTEDSUCCESSMESSAGE_H
#define CHARACTERSELECTEDSUCCESSMESSAGE_H

#include "src/protocol/network/types/data/game/character/choice/CharacterBaseInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class CharacterSelectedSuccessMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterSelectedSuccessMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterSelectedSuccessMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterSelectedSuccessMessage(FuncTree tree);
  CharacterSelectedSuccessMessage();

  QSharedPointer<CharacterBaseInformations> infos;
  bool isCollectingStats;

private:
  void _infostreeFunc(Reader *input);
  void _isCollectingStatsFunc(Reader *input);

  FuncTree _infostree;
};

#endif // CHARACTERSELECTEDSUCCESSMESSAGE_H