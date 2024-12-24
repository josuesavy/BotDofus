#ifndef DISPLAYNUMERICALVALUEPADDOCKMESSAGE_H
#define DISPLAYNUMERICALVALUEPADDOCKMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class DisplayNumericalValuePaddockMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_DisplayNumericalValuePaddockMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_DisplayNumericalValuePaddockMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_DisplayNumericalValuePaddockMessage(FuncTree tree);
  DisplayNumericalValuePaddockMessage();

  int rideId;
  int value;
  uint type;

private:
  void _rideIdFunc(Reader *input);
  void _valueFunc(Reader *input);
  void _typeFunc(Reader *input);
};

#endif // DISPLAYNUMERICALVALUEPADDOCKMESSAGE_H