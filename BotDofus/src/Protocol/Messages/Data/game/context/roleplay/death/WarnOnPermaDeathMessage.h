#ifndef WARNONPERMADEATHMESSAGE_H
#define WARNONPERMADEATHMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class WarnOnPermaDeathMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_WarnOnPermaDeathMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_WarnOnPermaDeathMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_WarnOnPermaDeathMessage(FuncTree tree);
  WarnOnPermaDeathMessage();

  bool enable;

private:
  void _enableFunc(Reader *input);
};

#endif // WARNONPERMADEATHMESSAGE_H