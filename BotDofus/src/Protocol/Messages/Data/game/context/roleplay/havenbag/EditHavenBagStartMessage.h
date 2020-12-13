#ifndef EDITHAVENBAGSTARTMESSAGE_H
#define EDITHAVENBAGSTARTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class EditHavenBagStartMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_EditHavenBagStartMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_EditHavenBagStartMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_EditHavenBagStartMessage(FuncTree tree);
  EditHavenBagStartMessage();
};

#endif // EDITHAVENBAGSTARTMESSAGE_H