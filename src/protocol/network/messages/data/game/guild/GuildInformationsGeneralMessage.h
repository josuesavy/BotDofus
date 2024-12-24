#ifndef GUILDINFORMATIONSGENERALMESSAGE_H
#define GUILDINFORMATIONSGENERALMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GuildInformationsGeneralMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildInformationsGeneralMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildInformationsGeneralMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildInformationsGeneralMessage(FuncTree tree);
  GuildInformationsGeneralMessage();

  bool abandonnedPaddock;
  uint level;
  double expLevelFloor;
  double experience;
  double expNextLevelFloor;
  uint creationDate;
  int score;

private:
  void _abandonnedPaddockFunc(Reader *input);
  void _levelFunc(Reader *input);
  void _expLevelFloorFunc(Reader *input);
  void _experienceFunc(Reader *input);
  void _expNextLevelFloorFunc(Reader *input);
  void _creationDateFunc(Reader *input);
  void _scoreFunc(Reader *input);
};

#endif // GUILDINFORMATIONSGENERALMESSAGE_H