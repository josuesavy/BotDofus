#ifndef MOODSMILEYRESULTMESSAGE_H
#define MOODSMILEYRESULTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class MoodSmileyResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MoodSmileyResultMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MoodSmileyResultMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MoodSmileyResultMessage(FuncTree tree);
  MoodSmileyResultMessage();

  uint resultCode;
  uint smileyId;

private:
  void _resultCodeFunc(Reader *input);
  void _smileyIdFunc(Reader *input);
};

#endif // MOODSMILEYRESULTMESSAGE_H