import * as React from 'react';

import { StyleSheet, View, Text, TextInput, Button } from 'react-native';
import { compute, randomNumber } from 'fibonachos';

export default function App() {
  const [rank, setRank] = React.useState(1);
  const [number, setNumber] = React.useState<null | number>(null);

  return (
    <View style={styles.container}>
      <View>
        <Text>Enter Fibonachos rank:</Text>
        <TextInput
          style={styles.input}
          value={rank.toString()}
          onChangeText={(text) => setRank(Number(text))}
          keyboardType="number-pad"
        />
      </View>
      <Text style={styles.result}>
        Result: {rank === 0 ? 'no nachos' : compute(rank - 1)}
      </Text>
      <View style={styles.separator} />
      <Text>Enter Fibonachos rank: {number}</Text>
      <Button
        title="Get random number"
        onPress={() => {
          setNumber(randomNumber());
        }}
      />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
  box: {
    width: 60,
    height: 60,
    marginVertical: 20,
  },
  input: {
    padding: 8,
    backgroundColor: '#FFDDDD',
    borderColor: '#340000',
    borderRadius: 8,
  },
  result: {
    fontSize: 24,
    textAlign: 'center',
    marginTop: 24,
  },
  separator: {
    height: 10,
    backgroundColor: 'black',
    width: '100%',
  },
});
