#ifndef WARNONPERMADEATHSTATEMESSAGE_H
#define WARNONPERMADEATHSTATEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class WarnOnPermaDeathStateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_WarnOnPermaDeathStateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_WarnOnPermaDeathStateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_WarnOnPermaDeathStateMessage(FuncTree tree);
  WarnOnPermaDeathStateMessage();

  bool enable;

private:
  void _enableFunc(Reader *input);
};

#endif // WARNONPERMADEATHSTATEMESSAGE_H