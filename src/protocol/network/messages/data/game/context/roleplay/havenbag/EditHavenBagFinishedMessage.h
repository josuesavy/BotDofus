#ifndef EDITHAVENBAGFINISHEDMESSAGE_H
#define EDITHAVENBAGFINISHEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class EditHavenBagFinishedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_EditHavenBagFinishedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_EditHavenBagFinishedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_EditHavenBagFinishedMessage(FuncTree tree);
  EditHavenBagFinishedMessage();
};

#endif // EDITHAVENBAGFINISHEDMESSAGE_H