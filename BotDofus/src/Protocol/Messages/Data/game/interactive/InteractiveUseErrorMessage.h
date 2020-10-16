#ifndef INTERACTIVEUSEERRORMESSAGE_H
#define INTERACTIVEUSEERRORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class InteractiveUseErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_InteractiveUseErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_InteractiveUseErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_InteractiveUseErrorMessage(FuncTree tree);
  InteractiveUseErrorMessage();

  uint elemId;
  uint skillInstanceUid;

private:
  void _elemIdFunc(Reader *input);
  void _skillInstanceUidFunc(Reader *input);
};

#endif // INTERACTIVEUSEERRORMESSAGE_H