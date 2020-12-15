#ifndef DOCUMENTREADINGBEGINMESSAGE_H
#define DOCUMENTREADINGBEGINMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class DocumentReadingBeginMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_DocumentReadingBeginMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_DocumentReadingBeginMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_DocumentReadingBeginMessage(FuncTree tree);
  DocumentReadingBeginMessage();

  uint documentId;

private:
  void _documentIdFunc(Reader *input);
};

#endif // DOCUMENTREADINGBEGINMESSAGE_H