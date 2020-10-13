#ifndef INVALIDPRESETSMESSAGE_H
#define INVALIDPRESETSMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class InvalidPresetsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_InvalidPresetsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_InvalidPresetsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_InvalidPresetsMessage(FuncTree tree);
  InvalidPresetsMessage();

  QList<uint> presetIds;

private:
  void _presetIdstreeFunc(Reader *input);
  void _presetIdsFunc(Reader *input);

  FuncTree _presetIdstree;
};

#endif // INVALIDPRESETSMESSAGE_H