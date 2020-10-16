#ifndef CHARACTERSELECTEDSUCCESSMESSAGE_H
#define CHARACTERSELECTEDSUCCESSMESSAGE_H

#include "src/Protocol/Types/Data/game/character/choice/CharacterBaseInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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