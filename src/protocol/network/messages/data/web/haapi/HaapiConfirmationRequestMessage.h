#ifndef HAAPICONFIRMATIONREQUESTMESSAGE_H
#define HAAPICONFIRMATIONREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class HaapiConfirmationRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HaapiConfirmationRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HaapiConfirmationRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HaapiConfirmationRequestMessage(FuncTree tree);
  HaapiConfirmationRequestMessage();

  double kamas;
  double ogrines;
  uint rate;
  uint action;

private:
  void _kamasFunc(Reader *input);
  void _ogrinesFunc(Reader *input);
  void _rateFunc(Reader *input);
  void _actionFunc(Reader *input);
};

#endif // HAAPICONFIRMATIONREQUESTMESSAGE_H