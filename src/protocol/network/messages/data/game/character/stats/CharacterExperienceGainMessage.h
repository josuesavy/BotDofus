#ifndef CHARACTEREXPERIENCEGAINMESSAGE_H
#define CHARACTEREXPERIENCEGAINMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class CharacterExperienceGainMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterExperienceGainMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterExperienceGainMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterExperienceGainMessage(FuncTree tree);
  CharacterExperienceGainMessage();

  double experienceCharacter;
  double experienceMount;
  double experienceGuild;
  double experienceIncarnation;

private:
  void _experienceCharacterFunc(Reader *input);
  void _experienceMountFunc(Reader *input);
  void _experienceGuildFunc(Reader *input);
  void _experienceIncarnationFunc(Reader *input);
};

#endif // CHARACTEREXPERIENCEGAINMESSAGE_H