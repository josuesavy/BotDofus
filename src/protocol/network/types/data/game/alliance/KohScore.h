#ifndef KOHSCORE_H
#define KOHSCORE_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class KohScore : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_KohScore(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_KohScore(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_KohScore(FuncTree tree);
  KohScore();
  bool operator==(const KohScore &compared);

  uint avaScoreTypeEnum;
  int roundScores;
  int cumulScores;

private:
  void _avaScoreTypeEnumFunc(Reader *input);
  void _roundScoresFunc(Reader *input);
  void _cumulScoresFunc(Reader *input);
};

#endif // KOHSCORE_H