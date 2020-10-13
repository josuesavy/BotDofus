#ifndef MOODSMILEYREQUESTMESSAGE_H
#define MOODSMILEYREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class MoodSmileyRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MoodSmileyRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MoodSmileyRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MoodSmileyRequestMessage(FuncTree tree);
  MoodSmileyRequestMessage();

  uint smileyId;

private:
  void _smileyIdFunc(Reader *input);
};

#endif // MOODSMILEYREQUESTMESSAGE_H