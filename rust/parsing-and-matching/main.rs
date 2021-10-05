use anyhow::Result;
use itertools::Itertools;

fn main() -> anyhow::Result<()> {
    let x: i64 = 3869;
    let (a, b, c) = include_str!("input.txt")
        .split('\n')
        .map(str::parse::<i64>)
        .collect::<Result<Vec<_>, _>>()?
        .into_iter()
        .tuple_combinations()
        .find(|(a, b, c)| a + b + c == x)
        .expect(&("No 3 numbers with sum ".to_owned()+&x.to_string()));

    dbg!((a, b, c));
    Ok(())
}
