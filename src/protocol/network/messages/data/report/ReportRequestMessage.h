#ifndef REPORTREQUESTMESSAGE_H
#define REPORTREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ReportRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ReportRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ReportRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ReportRequestMessage(FuncTree tree);
  ReportRequestMessage();

  double targetId;
  QList<uint> categories;
  QString description;

private:
  void _targetIdFunc(Reader *input);
  void _categoriestreeFunc(Reader *input);
  void _categoriesFunc(Reader *input);
  void _descriptionFunc(Reader *input);

  FuncTree _categoriestree;
};

#endif // REPORTREQUESTMESSAGE_H