import { createSlice, PayloadAction } from '@reduxjs/toolkit'
import type { RootState } from '../../store'

interface plotState {
  value: number[][]
}

const initialState: plotState = {
  value: [],
}

export const plotStateSlice = createSlice({
  name: 'plotState',
  initialState,
  reducers: {
    setPlotState: (state, payload: PayloadAction<{ i: number; j: number }>) => {
      state.value[payload.payload.i][payload.payload.j] =
        (state.value[payload.payload.i][payload.payload.j] + 1) % 4
    },
    setInitialState: (state, payload: PayloadAction<plotState>) => {
      state.value = payload.payload.value
    },
  },
})

export const { setPlotState, setInitialState } = plotStateSlice.actions

export const selectPlotState = (state: RootState) => state.plot.value

export default plotStateSlice.reducer
