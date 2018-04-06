const test = require('tape')
const spawn = require('child_process').spawn
const split = require('split2')

test('test.h using example-fail', t => {
  const child = spawn(__dirname + '/example-fail')
  const texts = []

  child.stdout.pipe(split()).on('data', data => {
    if (data.startsWith('# ')) {
      texts.push(data.trim())
    }
  })

  child.on('exit', code => {
    t.same(texts, [
      '# Testing bools',
      '# Testing ints',
      '# Result'
    ], 'correct descriptions')
    t.same(code, 1, 'example should fail')
    t.end()
  })
})

test('test.h using example-success', t => {
  const child = spawn(__dirname + '/example-success')
  const texts = []

  child.stdout.pipe(split()).on('data', data => {
    if (data.startsWith('# ')) {
      texts.push(data.trim())
    }
  })

  child.on('exit', code => {
    t.same(texts, [
      '# Testing bools',
      '# Testing ints',
      '# Result'
    ], 'correct descriptions')
    t.same(code, 0, 'example should succeed')
    t.end()
  })
})
